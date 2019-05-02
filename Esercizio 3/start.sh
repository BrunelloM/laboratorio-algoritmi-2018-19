#!/bin/sh
rm -rf ./out/*;
cd src;
javac -d ../out ./unionfindset/UnionFind.java || exit;
javac -d ../out ./unionfindsetusage/UnionFindMain.java || exit;
cd ../out/;
java unionfindsetusage/UnionFindMain;
