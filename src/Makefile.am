##AM_CPPFLAGS=$(DEPS_CFLAGS)
bin_PROGRAMS=interval_join axt_to_binary fill_reference_graph make_gc_map report_cnvs maps2bin find_spikes make_reference_graph make_donor_graph make_simple_coverage interleave_bam readbin make_ns find_mean_sd intRemove2
intRemove2_SOURCES=intRemove2.cpp include/interval.h
find_mean_sd_SOURCES=find_mean_sd.cpp include/defs.h include/InputReader.h bamtools/BamAux.h bamtools/zlib.h bamtools/zconf.h bamtools/BGZF.cpp bamtools/BamReader.cpp bamtools/BamWriter.cpp include/InputReader.h include/dbtypes.h
readbin_SOURCES=readbin.cpp include/dbtypes.h include/defs.h
make_ns_SOURCES=make_ns.cpp include/defs.h
maps2bin_SOURCES=maps2bin.cpp bamtools/BamAux.h bamtools/zlib.h bamtools/zconf.h bamtools/BGZF.cpp bamtools/BamReader.cpp bamtools/BamWriter.cpp include/dbtypes.h include/defs.h include/InputReader.h
#maps2bin_LDADD=-lz
interleave_bam_SOURCES=interleave_bam.cpp bamtools/BamAux.h bamtools/zlib.h bamtools/zconf.h bamtools/BGZF.cpp bamtools/BamReader.cpp bamtools/BamWriter.cpp 
#interleave_bam_LDADD=-lz
axt_to_binary_SOURCES=axt_to_binary.c include/graphtypes.h
fill_reference_graph_SOURCES=fill_reference_graph.c include/graphtypes.h
make_gc_map_SOURCES=make_gc_map.cpp include/dbtypes.h include/defs.h
report_cnvs_SOURCES=report_cnvs.cpp include/dbtypes.h include/graphtypes.h
find_spikes_SOURCES=find_spikes.c 
make_reference_graph_SOURCES=make_reference_graph.c include/graphtypes.h
make_donor_graph_SOURCES=make_donor_graph.cpp include/graphtypes.h include/dbtypes.h 
make_simple_coverage_SOURCES=make_simple_coverage.cpp include/dbtypes.h
interval_join_SOURCES=interval_join.cpp 
SUBDIRS=cluster post_analysis cs2-4.6 high-copy-count-regions 
EXTRA_DIST=flow_solve bamtools cnver.pl smoother.sh merge_intervals.py
