/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         God Bless Me     BUG Free Forever
*/

/***
 * 模拟法，画'Z'字
 * 用cnt计数，垂直方向有nRows个
 * 斜线方向上最多有nRows-2个（不包含第二列的开头）
 * 先按行存格式化后的字符串，然后再连接起来
 ***/
/*
class Solution {
public:
    string convert(string s, int nRows) {
        if (1 == nRows)
            return s;
        
        vector<string> vzigzag(nRows);
        int row = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (cnt < nRows)
                row = cnt;
            else
                row = 2*nRows - cnt - 2;
            vzigzag[row].push_back(s[i]);   // save the char to the right row
            
            if (++cnt == (2*nRows - 2))  // a new period
                cnt = 0;
        }
        
        string szz;
        for (int i = 0; i < vzigzag.size(); ++i)
            szz += vzigzag[i];
        return szz;
    }
};
*/

/***
 * 法2：找规律 一行一行处理
 * 可能在垂直方向和对角线方向取值
 * 第一行和最后一行只能在垂直方向取值， 步长为2*nRows-2
 * 对中间的行，即可以在垂直方向取值，步长仍为2*nRows-2,
 * 也可在对角线方向取值，步长也为2*nRows-2，不过起点变为i+(nRows-i-1)*2
 * 按照以上规律，一行一行处理，注意边界条件
 ***/
class Solution {
public:
    string convert(string s, int nRows) {
        if (s.empty() || (nRows <= 1) || (s.size() <= nRows))
            return s;
            
        const int n = s.size();
        int step = 2*nRows - 2;
        string szz;
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = i; j < n; j += step)
            {
                szz.push_back(s[j]);           // in vertical
                if ((i > 0) && (i < nRows-1))  // not the first or last row
                {
                    int k = j + (nRows - i - 1) * 2;  // index in the diagonal line
                    if (k < n)
                        szz.push_back(s[k]);
                }
            }
        }
        return szz;
    }
};

// 方法同上
/*
class Solution {
public:
    string convert(string s, int nRows) {
        if (0 == nRows) return "";
        if (1 == nRows) return s;
        
        vector<string> vzzg(nRows, "");
        const int n = s.size();
        int k = 0;
        while (k < n)
        {
            for (int i = 0; (i < nRows) && (k < n); ++i)
                vzzg[i] += s[k++];
            for (int i = nRows-2; (i > 0) && (k < n); --i)
                vzzg[i] += s[k++];
        }
        string sres;
        for (int i = 0; i < nRows; ++i)
            sres += vzzg[i];
        return sres;
    }
};
*/
class Solution {
public:
    string convert(string s, int nRows) {
        if (0 == nRows) return "";
        if (1 == nRows) return s;
        
        const int n = s.size();
        string sres;
        for (int i = 0; i < nRows; ++i)
        {
            int k = i;
            while (k < n)
            {
                sres += s[k];  // cur
                int i1 = k + (nRows - i - 1)*2; // next in this line
                if ((i != 0) && (i != nRows-1) && (i1 < n))
                    sres += s[i1];
                k += (nRows - 1)*2;
            }
        }
        return sres;
    }
};
