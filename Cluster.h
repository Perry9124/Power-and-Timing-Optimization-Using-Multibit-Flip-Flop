#ifndef CLUSTER_H
#define CLUSTER_H   
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include "Board.h"
using namespace std;
class Cluster {
private:
    int n;
    int k; //����k��cluster
    int l; //�C��cluster�A����l��cluster
    int epochs; //�Npoint���諸���N����
    int maxBits;
    double MinVariance;
    double Max; // max dimension of board
    struct Point {
        double x, y;
        int cluster;
        Point() : x(0), y(0), cluster(-1) {}
        Point(double x, double y, int cluster = -1) : x(x), y(y), cluster(cluster) {}
        double distance(Point p) {
            return abs(x - p.x) + abs(y - p.y);
        }
    };
    vector<Point> DataPoints; //�Ҧ�flip flop���N���I
    vector<vector<Point>> KClusters; //�`�@k��cluster�A�C��cluster�̥]�t��points
    vector<vector<vector<Point>>> KLClusters; //�`�@k��cluster�A�C��cluster�A����l��cluster�A�C��cluster�̥]�t��points
    vector<Point> centroids; //cluster��߮y��
    vector<vector<Point>> KCentroids; //�`�@k��cluster�A�C��cluster�A����l��cluster�A�C��cluster�����
    vector<int> counts; //cluster����points�ƶq
    vector<vector<int>> KCounts; //�`�@k��cluster�A�C��cluster�A����l��cluster�A�C��cluster��points�ƶq
public:
    Cluster();
    Cluster(int, int, int, int, int, double, double);
    void initializeVector(int, int);
    double variance();
    void kMeansClustering(vector<Point>&, vector<Point>&, vector<int>&, int, int);
    void readData(Board&);
    void kmeans(Board&);
};

#endif#pragma once
