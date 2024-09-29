#include <iostream>

using namespace std;

int N;
int inorder[100001];
int postorder[100001];
int idx[100001];

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd)
		return;

	int root = postorder[postEnd];
	int rootIndex = idx[root];
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;

	cout << root << " ";

	preorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
	preorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N; 
    for (int i = 1; i <= N; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        cin >> postorder[i];

    preorder(1, N, 1, N);
    
    return 0;
}