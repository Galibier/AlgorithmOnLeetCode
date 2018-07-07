class Solution {
private:
	int GCD(int a, int b) {
		return (b == 0) ? a : GCD(b, a % b);
	}
public:
	string fractionAddition(string expression) {
		istringstream in(expression);
		int A = 0, B = 1, a, b;
		char _;
		while (in >> a >> _ >> b) {
			A = A * b + a * B;
			B *= b;
			int g = abs(GCD(A, B));
			A /= g;
			B /= g;
		}
		return to_string(A) + '/' + to_string(B);
	}
};