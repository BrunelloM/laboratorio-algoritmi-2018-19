#!/bin/sh
rm -rf ./out/*;
mkdir ./out/;
cd src;
javac -d ../out/ ./kruskalAlgorithmUsage/*.java || exit;
#javac -d ../out/ -cp ".:/graph.*:/usr/share/java/junit4.jar:/usr/share/java/hamcrest-core-1.3.jar:" ./test/*.java || exit;
