
class Info
{
public:
    bool is_bst;
    int maxBSTsize;
    int leftmax;
    int rightmin;
    Info()
    {
        is_bst = true;
        maxBSTsize = 0;
        leftmax = INT_MIN;
        rightmin = INT_MAX;
    }
};
Info greatestBSTinBT(node *root)
{

    if (root == NULL)
    {
        return Info();
    }

    Info left = greatestBSTinBT(root->left);
    Info right = greatestBSTinBT(root->right);

    Info ans;
    if (root->data >= left.leftmax && root->data < right.rightmin &&
        left.is_bst && right.is_bst)
    {
        ans.maxBSTsize = left.maxBSTsize + right.maxBSTsize + 1;
        ans.is_bst = true;
        ans.leftmax = max(left.leftmax, root->data);
        ans.rightmin = min(right.rightmin, root->data);
    }
    else
    {
        ans.is_bst = false;
        ans.maxBSTsize = max(left.maxBSTsize, right.maxBSTsize);
    }
    return ans;
}
