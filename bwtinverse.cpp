#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;

typedef pair<char, int> iPair;



string InverseBWT(const string& bwt) {
    string text = "";
    string sotred_bwt = "";
    vector<int> couts;
    vector<char> ch;
    vector<vector<int>> index_BWT(5);
    vector<int> index_FirstColumn(bwt.length());
    vector<int> index_LastColumn(bwt.length());
    ch.push_back('$');
    ch.push_back('A');
    ch.push_back('C');
    ch.push_back('G');
    ch.push_back('T');
    vector<iPair> TextPair(bwt.length());
    vector<iPair> TextPairSorted(bwt.length());
    int A_cnt = 0;
    int C_cnt = 0;
    int G_cnt = 0;
    int T_cnt = 0;

    for (size_t i = 0; i < bwt.length(); i++)
    {
        TextPair[i].first = bwt[i];
        TextPair[i].second = i;

        if (bwt[i] == 'A')
        {
            A_cnt++;
            index_BWT[1].push_back(i);
        }
        else if (bwt[i] == 'C')
        {
            C_cnt++;
            index_BWT[2].push_back(i);
        }
        else if (bwt[i] == 'G')
        {
            G_cnt++;
            index_BWT[3].push_back(i);
        }
        else if (bwt[i] == 'T')
        {
            T_cnt++;
            index_BWT[4].push_back(i);
        }
        else if (bwt[i] == '$')
        {

            index_BWT[0].push_back(i);
        }
    }
    couts.push_back(1);
    couts.push_back(A_cnt);
    couts.push_back(C_cnt);
    couts.push_back(G_cnt);
    couts.push_back(T_cnt);
    TextPairSorted = TextPair;

    // TextPairSorted[0].first = '$';
    int start_Index = 0;
    for (size_t i = 0; i < couts.size(); i++)
    {
        for (size_t j = 0; j < couts[i]; j++)
        {
            TextPairSorted[start_Index + j].first = ch[i];
            TextPairSorted[start_Index + j].second = index_BWT[i][j];
            index_FirstColumn[index_BWT[i][j]] = start_Index + j;
            index_LastColumn[start_Index + j] = start_Index + j;

            // cout << index_BWT[i][j] << "  " << start_Index + j << endl;
        }

        start_Index = start_Index + couts[i];

    }

    // cout << "------";

     // TextPairSorted = TextPair;

     //sort(TextPairSorted.begin(), TextPairSorted.end());

     /*
     for (size_t i = 0; i < index_LastColumn.size(); i++)
     {
       cout << index_FirstColumn[i] << "   " << index_LastColumn[i] << endl;
     }
     */


    char c = TextPair[0].first;
    size_t c_index = TextPair[0].second;
    //text.push_back(c);
    //int index;

    iPair target = { c, c_index };


    c_index = 0;

    for (size_t i = 0; i < TextPair.size(); i++)
    {
        //auto it = find(TextPairSorted.begin(), TextPairSorted.end(), target);
        //c_index = std::distance(TextPairSorted.begin(), it);
        c_index = index_LastColumn[c_index];
        // cout << c_index;
        c = TextPair[c_index].first;
        text.push_back(c);
        //TextPairSorted[c_index].first = '-';

        c_index = index_FirstColumn[c_index];

        //target = {c, c_index};
    }

    text.pop_back();
    //cout << text << endl;
    reverse(text.begin(), text.end());
    //cout << text << endl;
    text.push_back('$');

    /*
    sotred_bwt = bwt;

    char c = bwt[0];
    text.push_back(c);
    int index;

    sort(sotred_bwt.begin(), sotred_bwt.end());

    for (size_t i = 1 ; i < bwt.length(); i++)
    {
      index = sotred_bwt.find(c);
      c = bwt[index];
      text.push_back(c);
      sotred_bwt[index] = '-';


    }

    text.pop_back();
    //cout << text << endl;
    reverse(text.begin(), text.end());
    //cout << text << endl;
    text.push_back('$');
  */
    return text;
}

int main() {
    string bwt;
    cin >> bwt;
    cout << InverseBWT(bwt) << endl;
    return 0;
}
