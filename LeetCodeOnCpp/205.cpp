class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char, char> charMap;
		map<char, char> charMapR;
		for (int i = 0; i < s.size(); i++) {
			charMap.insert({ s[i], t[i] });
			charMapR.insert({ t[i], s[i] });
		}
		string tRecon, sRecon;
		for (int i = 0; i < s.size(); i++) {
			tRecon += charMap[s[i]];
			sRecon += charMapR[t[i]];
		}
		return tRecon == t && sRecon == s;
	}
};