#!/bin/sh
rm -rf ./out/*;
mkdir ./out/graph  ./out/unionfindset ./out/kruskalAlgorithm ./out/kruskalAlgorithmUsage
cd src;
javac -d ../out/ ./kruskalAlgorithmUsage/*.java || exit
cd ../out/;
java kruskalAlgorithmUsage/KruskalAlgorithmUsage $1;
