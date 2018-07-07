class Solution {
public:
	int compress(vector<char>& chars) {
		int indexWrite = 0;
		for (int indexRead = 0; indexRead < chars.size(); ++indexRead) {
			int count = 1;
			while (indexRead + 1 < chars.size() && chars[indexRead] == chars[indexRead + 1]) {
				++count;
				++indexRead;
			}
			chars[indexWrite++] = chars[indexRead];

			if (count >= 2) {
				string tmpStr = std::to_string(count);
				for (char ch : tmpStr)
					chars[indexWrite++] = ch;
			}
		}
		return indexWrite;
	}
};