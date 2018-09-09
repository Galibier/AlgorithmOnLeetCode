import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class BinaryTreeZigzagLevelOrderTraversal {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        boolean reverse = true;

        while (!stack.isEmpty()) {
            Stack<TreeNode> next = new Stack<>();
            List<Integer> row = new LinkedList<>();
            while (!stack.isEmpty()) {
                TreeNode curr = stack.pop();
                if (curr != null) {
                    row.add(curr.val);
                    if (reverse) {
                        next.push(curr.left);
                        next.push(curr.right);
                    } else {
                        next.push(curr.right);
                        next.push(curr.left);
                    }
                }
            }

            if (!row.isEmpty()) {
                res.add(row);
            }
            stack = next;
            reverse = !reverse;
        }
        return res;
    }
}
