#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string To_Upper(string Str)
{
    transform(Str.begin(), Str.end(), Str.begin(), ::toupper);
    return Str;
}

class Analyzer {
public:
    Analyzer() = default;
    Analyzer(string& s, string& word){
        word_ = To_Upper(word);
        me_ = findSelf(s);
        body_ = findBody(s);
        getOutLink(s);

        calculateBasicScore();

        out_link_size_ = out_links_.size();
    }

    void printMe(){
        cout << "me : " << me_ << endl;
        cout << "body : [" << body_ << "]" << endl;

        cout << "--------------out-link----------" << endl;
        for(auto item : out_links_){
            cout << item << endl;
        }
        cout << "--------------out-link----------" << endl;

        cout << "basic : " << basic_score_ << endl;
        cout << "out-link-size : " << out_link_size_ << endl;
    }

    string getUrl(){
        return me_;
    }

    vector<string>& getOutLinks(){
        return out_links_;
    }

    int getBasicScore(){
        return basic_score_;
    }

    int getLinksSize(){
        return out_link_size_;
    }

    void setLinkScore(float score){
        link_score_ = score;
    }

    float getLinkScore() {
        return link_score_;
    }
    int index;


private:

    int calculateBasicScore(){
        auto up_body = To_Upper(body_);

        int score = 0;
        string str;
        for(auto w : up_body){
            if(isalpha(w) == 0){
                if(str == word_){
                    score++;
                }
                str = "";
            }else{
                str += w;
            }
        }

        if(!str.empty()){
            if(str == word_){
                score++;
            }
        }

        basic_score_ = score;
    }

    void getOutLink(string& s){
        const string olink1 = "<a href=\"https://";
        const string olink2 = "\">";

        int start = 0;
        int end = 0;
        while (true) {
            start = s.find(olink1, end + olink2.length());
            if (start == string::npos) break;
            end = s.find(olink2, start + olink1.length());
            int len = end - (start + olink1.length());
            auto link = s.substr(start + olink1.length(), len);
            out_links_.push_back(link);
        }

    }

    string findSelf(string& s){

        const string mlink1 = "<meta property=\"og:url\" content=\"https://";
        const string mlink2 = "\"";

        int start = s.find(mlink1);
        int end = s.find(mlink2, start + mlink1.length());
        int len = end - (start + mlink1.length());
        auto my_url = s.substr(start + mlink1.length(), len);

        return my_url;
    }
    string findBody(string& s){
        const string body_start = "<body>";
        const string body_end = "</body>";

        int start = s.find(body_start);
        int end = s.find(body_end);
        int len = end - (start + body_start.length());
        string body = s.substr(start + body_start.length(), len);

        bool aTag = false;
        string str = "";
        for (int j = 0; j < body.length(); ++j) {
            if (body[j] == '<') {
                aTag = true;
                continue;
            }
            if (body[j] == '>') {
                aTag = false;
                continue;
            }
            if (aTag == false)
                str += body[j];
        }

        return str;

    }

    string me_;
    string body_;
    string word_;

    int basic_score_ = 0;
    int out_link_size_ = 0;
    float link_score_ = 0.;
    float total = 0.;
    vector<string> out_links_;

};

int solution(string word, vector<string> pages) {
    int answer = 0;
    unordered_map<string, Analyzer> ana_map;

    for(auto page : pages){
        Analyzer temp = Analyzer(page, word);
        ana_map.insert({temp.getUrl(), temp});
    }

    unordered_map<string, float> score_map;
    for(const auto& item : ana_map){
        auto url = item.first;
        auto ana = item.second;
        score_map[url] += (float )ana.getBasicScore();

        auto out_links = ana.getOutLinks();
        for(auto link : out_links){
            score_map[link] += (float )ana.getBasicScore() / (float )ana.getLinksSize();
        }

    }



    return answer;
}


int main() {

/**
 *
    word : blind
    pages : "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
 */

    string s = "blind";
    vector<string> vec;
    vec = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>",
           "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"};

    auto rtn = solution(s, vec);

    cout << rtn << endl;

    return 0;
}