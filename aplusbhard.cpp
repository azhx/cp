#include <bits/stdc++.h>
using namespace std;
#define toDigit(x) (x-'0')

int eval (string x, string y) {
    if (x.length() == y.length()){
        for (unsigned int i = 0; i < x.length(); i++) {
            if (x[i] < y[i]) {
                return 1;
            }
            if (x[i] > y[i]) {
                return 0;
            }
        }
    } else if (x.length() < y.length()){
        return 1;
    }
    return 0;// if 0, x is larger, if 1, y is larger
}

tuple<string, string, long> pad (string x, string y) {
    long len = 0;
    if (eval(x, y) == 0){
        len = x.length();
        int pad = x.length() - y.length();
        y = y.insert(0, pad, '0');
    } else {
        len = y.length();
        int pad = y.length() - x.length();
        x = x.insert(0, pad, '0');
    }
    return make_tuple(x, y, len);
}

string add(string x, string y) {
    string result = "";
    long len;
    int carried = 0;
    tie(x, y, len) = pad(x, y);
    for (int i = len-1; i > 0; i--) {
        int sum = toDigit(y[i]) + toDigit(x[i]) + carried;
        if (to_string(sum).length() > 1) {
            carried = toDigit(to_string(sum)[0]);
            sum = toDigit(to_string(sum)[1]);
        } else {
            carried = 0;
        }
        result.insert(0, to_string(sum));
    }
    result.insert(0, to_string(toDigit(x[0]) + toDigit(y[0]) + carried));
    return result;
}

string sub(string x, string y) {
    string result = "";
    long len;
    bool borrowed = false;
    tie(x, y, len) = pad(x, y);
    for (int i = len-1; i > -1; i--) {
        int top = toDigit(x[i]);
        int bot = toDigit(y[i]);
        int diff;
        if (borrowed == true) {
            top = top - 1;
        }
        if (top < bot) {
            borrowed = true;
            diff = top + 10 - bot;
        } else {
            borrowed = false;
            diff = top - bot;
        }
        if (i != 0) {
          result.insert(0, to_string(diff));
        } else if (i == 0 && diff != 0){
          result.insert(0, to_string(diff));
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<string> results;

    for (int i = 0; i < N; i++) {
        string x, y;
        cin >> x >> y;
        if ((x[0] == '-') && (y[0] == '-')) {
            string result = add(x.substr(1), y.substr(1));
            results.push_back('-' + result);
        } else if ((x[0] == '-') && (y[0] != '-')){
            x = x.substr(1);
            if (eval(x, y) == 0){
                string result = sub(x, y);
                results.push_back('-'+ result);
            } else{
                string result = sub(y, x);
                results.push_back(result);
            }
        } else if ((x[0] != '-') && (y[0] == '-')){
            y = y.substr(1);
            if (eval(x, y) == 0){
                string result = sub(x, y);
                results.push_back(result);
            } else {
                string result = sub(y, x);
                results.push_back('-'+ result);
            }
        } else {
            string result = add(x, y);
            results.push_back(result);
        }
    }
    for (unsigned int i = 0; i < results.size(); i++) {
      if (results[i] == "-" || results[i] == ""){
        cout << '0' << endl;
      } else {
        cout << results[i] << endl;
      }
    }
    return 0;
}
