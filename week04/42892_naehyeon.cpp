#include <bits/stdc++.h>
using namespace std;
struct node {
    int index;
    int x;
    int y;
    int right_index;
    int left_index;
};
vector<node> treeinfo;

bool comp(node a, node b){
    if(a.y > b.y){
        return true;
    } else if(a.y == b.y && a.x < b.x){
        return true;
    } else return false;
}

void preord(node* root, vector<int>& answer){
    if(root == NULL) return;
    
    answer.push_back((root->index) + 1);
    
    if(root->left_index == -1){
        preord(NULL, answer);
    } else preord( &treeinfo[root->left_index], answer );
    
    if(root->right_index == -1){
        preord(NULL, answer);
    } else preord( &treeinfo[root->right_index], answer );
    
}

void postord(node* root, vector<int>& answer){
    if(root == NULL) return;
    
    if(root->left_index == -1){
        postord(NULL, answer);
    } else postord( &treeinfo[root->left_index], answer );
    
    if(root->right_index == -1){
        postord(NULL, answer);
    } else postord( &treeinfo[root->right_index], answer );
    
    answer.push_back((root->index) + 1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    for(int i = 0; i < nodeinfo.size(); i++)
        treeinfo.push_back({ i, nodeinfo[i][0], nodeinfo[i][1], -1, -1 });
    sort(treeinfo.begin(), treeinfo.end(), comp);
    
    int gizun;
    for(int i = 1; i < treeinfo.size(); i++){
        gizun = 0;
        while(true){
            //cout << "now gizun : " << gizun << "\n";
            if(treeinfo[i].x < treeinfo[gizun].x){ // left
                if(treeinfo[gizun].left_index == -1){
                    treeinfo[gizun].left_index = i;
                    break;
                }
                gizun = treeinfo[gizun].left_index;
            } else { // right
                if(treeinfo[gizun].right_index == -1){ 
                    treeinfo[gizun].right_index = i;
                    break;
                }
                gizun = treeinfo[gizun].right_index;
            }
        }
    }
    
     preord(&treeinfo[0], answer[0]);
    postord(&treeinfo[0], answer[1]);
    
    return answer;
}
