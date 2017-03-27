#include "Utils.h"

Utils::Utils(){
}


// Generate the Euclidean norm of v
string Utils::Norm(vector<string> v){

    string sqrSum;
    for( int i=0; i<v.size() - 1; i++ ){

        string sqrDiff;
        sqrDiff = "( " + v[i] + " )^ 2 + ";
        sqrSum += sqrDiff;
    }

    // add last element squared term
    string sqrDiff = "( " + v[v.size()-1] + " )^ 2";
    sqrSum += sqrDiff;

    return "( " + sqrSum + " )^(-1)";
}

// Numeric norm of v
double Utils::Norm(vector<double> v){

    double sqrSum = 0;
    for( int i=0; i<v.size(); i++ ){
        sqrSum += pow(v[i],2);
    }
    return sqrt(sqrSum);
}

// v1 -  v2
vector<double> Utils::Diff(vector<double> v1, vector<double> v2){

    vector<double> diff;
    for( int i=0; i<v1.size(); i++ ){
        diff.push_back(v1[i] - v2[i]);
    }
    return diff;
}

// Apply operator to vector elements
vector<string> Utils::Op(vector<string> v1, vector<string> v2, string op){

    vector<string> res;

    for(int i=0; i<v1.size(); i++){
        res.push_back("( " + v1[i] + " " + op + " " + v2[i] + " )");
    }
    return res;
}

// v/n
vector<double> Utils::Div(vector<double> v, double n){
    for( int i=0; i<v.size(); i++ ){
        v[i] = v[i]/n;
    }
    return v;
}

// Generate the Euclidean distance formula dist(x,y) < eps
string Utils::Dist(vector<string> v1, vector<string> v2, string eps){

    vector<string> diffs;
    for(int i=0; i<v1.size(); i++){
       diffs.push_back( v1[i] + " - " + v2[i] );
    }

    return this->Norm(diffs) + " < " + eps;
}

// Distance of v from the line passing through p1 and p2
string Utils::DistFromLine(vector<string> wp, vector<double> p1, vector<double> p2, string eps){

    vector<string> t = this->ToString(Div( Diff(p2,p1), Norm(Diff(p2,p1))));
    vector<string> ws_wp = this->Op(ToString(p1),wp,"-");
    vector<string> ws_wp_tt = Op(Op(ws_wp,t,"*"),t,"*");
    string dist = Norm( Op(ws_wp,ws_wp_tt,"-") );

    return dist + " < " + eps;
}


// Double to string
string Utils::ToString(double n){
    ostringstream strs;
    strs << n;
    return strs.str();
}

// Doubles to strings
vector<string> Utils::ToString(vector<double> n){
    vector<string> strs;
    for(int i=0; i<n.size(); i++){
        strs.push_back(this->ToString(n[i]));
    }
    return strs;
}

