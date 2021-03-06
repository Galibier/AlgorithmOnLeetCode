import java.util.Stack;

public class TrappingRainWater {
    public int trap(int[] height) {
        if (height == null) {
            return 0;
        }
        Stack<Integer> s = new Stack<>();
        int i = 0, maxWater = 0, maxBotWater = 0;
        while (i < height.length) {
            if (s.isEmpty() || height[i] <= height[s.peek()]) {
                s.push(i++);
            } else {
                int bot = s.pop();
                maxBotWater = s.isEmpty() ? 0 : (Math.min(height[s.peek()], height[i]) - height[bot]) * (i - s.peek() - 1);
                maxWater += maxBotWater;
            }
        }
        return maxWater;
    }
}
