public class RecoverBinarySearchTree {
    TreeNode firstElement = null;
    TreeNode secondElement = null;
    TreeNode preElement = new TreeNode(Integer.MIN_VALUE);

    public void recoverTree(TreeNode root){
        traverse(root);
        int temp = firstElement.val;
        firstElement.val = secondElement.val;
        secondElement.val =temp;
    }
}
