#!/bin/sh
rm -rf ./out/*;
mkdir ./out/graph  ./out/unionfindset ./out/kruskalAlgorithm;
cd src;
javac  -d ../out/graph ./graph/Vertex.java || exit;
javac  -d ../out/graph ./graph/LabeledEdge.java || exit;
javac  -d ../out/graph ./graph/LabeledGraph.java || exit;
javac  -d ../out/unionfindset ./unionfindset/*.java || exit;
javac  -d ../out/kruskalAlgorithm ./kruskalAlgorithm/*.java || exit;
cd ../out/;
