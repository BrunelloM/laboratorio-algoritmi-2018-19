#!/bin/sh
rm -rf ./out/*;
cd src;
javac -d ../out ./graph/Graph.java || exit;
javac -d ../out ./graphusage/GraphUsage.java || exit;
cd ../out/;
java unionfindsetusage/UnionFindMain;
