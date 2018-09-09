public class FlattenBinaryTreetoLinkedList {
    public void flatten(TreeNode root){
        TreeNode cur = root, pre = root;
        while(cur!=null){
            if(cur.left!=null){
                pre = cur.left;
                while(pre.right!=null&&pre.right!=cur){
                    pre = pre.right;
                }
                if(pre.right==null){
                    pre.right=cur;
                    cur = cur.left;
                }else{
                    TreeNode right = cur.right;
                    cur.right = cur.left;
                    cur.left = null;
                    pre.right = right;
                    cur = right;
                }
            }else{
                cur = cur.right;
            }
        }
    }
}
