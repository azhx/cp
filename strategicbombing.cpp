#include <bits/stdc++.h>
using namespace std;
bool graph[26][26];
int cnt;

int main (){
    vector<string> bridges;
    while (true){
        char mystr[2];
        scanf("%s", mystr);
        if (mystr[0] == '*' && mystr[1] =='*'){
            break;
        }
        string push = mystr;
        graph[mystr[0]-'A'][mystr[1]-'A'] = true;
        graph[mystr[1]-'A'][mystr[0]-'A'] = true;
        bridges.push_back(push);
    }
    for (int i = 0; i< bridges.size();i++){
        graph[bridges[i][0]-'A'][bridges[i][1]-'A'] = false;
        graph[bridges[i][1]-'A'][bridges[i][0]-'A'] = false;
        bool vis[26]; memset(vis, false, sizeof(vis));
        queue<int> q; q.push(0); vis[0]= true;
        while (!q.empty()){
            int v = q.front(); q.pop();
            for (int j = 0; j < 26; j++){
                if (vis[j] == false && graph[v][j] == true){
                        q.push(j);
                        vis[j] = true;
                }
            }
        }
        if (vis[1] == false){
            printf("%s\n", bridges[i].c_str());
            cnt++;
        }
        graph[bridges[i][0]-'A'][bridges[i][1]-'A'] = true;
        graph[bridges[i][1]-'A'][bridges[i][0]-'A'] = true;
    }
    printf("There are %d disconnecting roads.\n", cnt);
    return 0;
}