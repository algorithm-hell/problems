#include <bits/stdc++.h>

using namespace std;

struct tree {
    int x,y,index;
    tree *left;
    tree *right;
};

bool cmp(tree a, tree b){
		// y 내림차손 x 오름차순
    if (a.y == b.y){
        return a.x < b.x;
    }
    return a.y >= b.y;
}

void make_tree(tree *root, tree *child){
    if (root->x > child->x){
        if (root->left == NULL){
            root->left = child;
            return;
        }
        make_tree(root->left, child);
    }
    else {
        if (root->right == NULL){
            root->right = child;
            return;
        }
        make_tree(root->right, child);
    }
}

void preOrder(tree *root, vector<int> &ans){
    if (root == NULL) return;
    ans.push_back(root->index);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}
void postOrder(tree *root, vector<int> &ans){
    if (root == NULL) return;
    postOrder(root->left, ans);
    postOrder(root->right, ans);
    ans.push_back(root->index);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<tree> trees;
    int i = 0;
    for (auto node: nodeinfo){
        int x = node[0], y = node[1];
        trees.push_back({x,y,i+1, NULL, NULL});
        i++;
    }
    sort(trees.begin(), trees.end(), cmp); // 정렬
    tree *root = &trees[0]; // 가장 앞에 있는게 루트 원소
    for (i=1; i<trees.size(); i++){
        make_tree(root, &trees[i]); // 루트에 대해 각각의 노드에서 뻗어나감
    }
    vector<int> ans1, ans2;
    preOrder(root, ans1);
    postOrder(root, ans2);
    answer.push_back(ans1);
    answer.push_back(ans2);
    
    return answer;
}
