#include <bits/stdc++.h>

using namespace std;

bool printerr(vector<bool>& err) {
    if (err[1]) { cout << "E1" << endl; return true; }
    else if (err[2]) { cout << "E2" << endl; return true; }
    else if (err[3]) { cout << "E3" << endl; return true; }
    else if (err[4]) { cout << "E4" << endl; return true; }
    else if (err[5]) { cout << "E5" << endl; return true; }
    else if (err[6]) { cout << "E6" << endl; return true; }

    return false;
}

int main() {

    string line;
    getline(cin, line);
    vector<vector<int>> G(26,vector<int>());
    vector<int> P(26,-1);
    unordered_set<int> pairs;

    regex rgx("\\(([A-Z]),([A-Z])\\)");

    vector<bool> err(6,false);

    int start = 0;
    int pos = line.find(" ");
    while (pos != string::npos) {
        line = line.substr(start);
        string substr = line.substr(0,pos);
        start = pos+1;
        pos = line.find(" ");

        if (!regex_match(substr,rgx)) {
            err[1] = true;
            break;
        }

        smatch m;
        regex_search(substr, m, rgx);
        int parent = ((string)m[1])[0] - 'A';
        int child = ((string)m[2])[0] - 'A';
        int p = parent*100 + child;

        if (pairs.find(p) != pairs.end()) {
            err[2] = true;
            break;
        }
        pairs.insert(parent*100 + child);


        G[parent].push_back(child);
        if (G[parent].size() > 2) {
            err[3] = true;
            break;
        }
        if (P[child] == -1 || P[child] == 0) P[child] = parent;
        else {
            err[6] = true;
            break;
        }
        if (P[parent] == -1) P[parent] = 0;
    }

    if (printerr(err)) return 0;

    // only have to check for E4 and E5 now
    // E4: two (or more) disjoint trees
    // E5: cycle check
    // both doable by DFS

    // ? how do we get the root in the first place
    // the root is the node with no parent
    int root = -1;
    for (int i=0; i<26; i++) {
        if (P[i] == 0) {
            root = i;
            break;
        }
    }

    stack<int> S;
    vector<bool> visited(26, false);
    S.push(root);
    visited[root] = true;
    while (!S.empty() && !err[5]) {
        int v = S.top();
        S.pop();
        for (int i : G[v]) {
            if (!visited[i]) {
                S.push(i);
                visited[i] = true;
            }
            else {
                err[5] = true;
                break;
            }
        }
    }

    if (printerr(err)) return 0;

    for (int i=0; i<26; i++) {
        if (G[i].size() > 0 && !visited[i]) {
            err[4] = true;
            break;
        }
    }

    printerr(err);

    return 0;
}
