#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#include "include/dbtypes.h"
#include "include/defs.h"
#include "include/InputReader.h"
#include "bamtools/BamReader.h"
#include "bamtools/BamAux.h"

using namespace BamTools;
string sbuf;
vector<string> ref_names;
typedef pair<string,int> ref_pair;
typedef map<string,int> ref_map_t;
ref_map_t ref_names_map;
vector<ofstream *> outf;


// append every mapping with the norm odds, modified chromosome name, and dump it
void process_block(deque<Map_t> & block) {
	if (block.size() == 0 || 0 == strcmp(block[0].ref_name, "-1")) return;

	//note normodds calculation uses all of the mappings, not just to the current chromosomes.
	double normodds = 1.0 / block.size(); 
	for (int i = 0; i < block.size(); i++) {
		block[i].normodds = normodds;
		ref_map_t::iterator it = ref_names_map.find(block[i].ref_name); //Identify reference index
		if (it != ref_names_map.end()) {
			int file_index = it->second; 
			outf[file_index]->write((char *) & block[i], sizeof(block[i]));
		}
	}
	return;
}

void usage( int argc, char ** argv) {
	printf("Usage: %s map_list ref_names input_format \n", argv[0]);
	cout << "\tmap_list     : file with names of mapping files.\n";
	cout << "\tref_names    : file with names of reference sequences.\n";
	cout << "\tinput_format : format of mapping files, either \"bam\" or \"txt\".\n";
	cout << endl;
	exit(1);
}

int main ( int argc, char ** argv) {
	if (argc != 4) usage(argc, argv);
	vector<string> map_list;
	read_file_into_vector(argv[1], map_list);
	read_file_into_vector(argv[2], ref_names);
	string input_format = argv[3];
	long read_id = 0;

	//open outputfiles and initialize ref_names_map
	outf.resize(ref_names.size());
	for (int i = 0; i < ref_names.size(); i++)  {
		ref_names_map.insert(make_pair(ref_names[i], i));
		outf[i] = new ofstream;
		open_file_binary(*outf[i], ref_names[i]  + ".rmap");
	}

	//read in the read mappings, grouping them into blocks with the same read_id.  
	//Each block is then handled in process_block
	uint64_t lastReadId = -1;
	for (int map_file_index = 0; map_file_index < map_list.size(); map_file_index++) {
		InputReader reader(input_format, map_list[map_file_index], lastReadId + 1);
		Map_t mapt;
		deque<Map_t> block;
		string lastReadName = "2paclives";
		while (reader.getNext(mapt)) {
			if (lastReadId != mapt.read_id) {
				process_block(block);  
				block.clear();
			} 
			lastReadId = mapt.read_id;
			block.push_back(mapt);
		}
		process_block(block);
		block.clear();
	}

	//close files
	for (int i = 0; i < outf.size(); i++) {
		outf[i]->close();
		delete outf[i];
	}
	return 0;	
}
