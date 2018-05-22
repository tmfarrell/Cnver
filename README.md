## CNVer

*This fork compiles on macOS (Sierra 10.12.6), while the master does not.*

To install: 

```bash 
#!/usr/bin/env bash 

git clone https://github.com/tmfarrell/Cnver.git
cd Cnver

./configure
make
export CNVer=$PWD

alias cnver="perl $CNVer/src/cnver.pl"

```

See [the paper](https://genome.cshlp.org/content/20/11/1613.full.pdf) for more details on its methodology/ algorithms. 