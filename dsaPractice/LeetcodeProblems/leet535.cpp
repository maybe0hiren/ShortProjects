#include <iostream>
#include <unordered_map>

std::string characterSet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::unordered_map<std::string,std::string> encodingMap;
std::unordered_map<std::string,std::string> decodingMap;
long long id = 0;

std::string createCode(long long id){
    std::string code;
    while(id>0){
        code += characterSet[id%62];
        id /= 62;
    }
    while(code.length()<6){
        code += '0';
    }
    return code;
}

std::string encode(std::string longUrl){
    std::string code;
    if(encodingMap.count(longUrl) == 1){
        return "http://tinyurl.com/" + encodingMap[longUrl];
    }
    code = createCode(id);
    id++;
    encodingMap[longUrl] = code;
    decodingMap[code] = longUrl;
    std::cout << "http://tinyurl.com/" + code << "\n";

    return "http://tinyurl.com/" + code;
}

std::string decode(std::string shortUrl){
    std::string code = shortUrl.substr(19);
    if(decodingMap.count(code) == 1){
        std::cout << decodingMap[code] << "\n";
        return decodingMap[code];
    }
    return "";
}

int main(){
    std::string longUrl = "https://leetcode.com/problems/design-tinyurl";
    std:: string shortUrl = encode(longUrl);
    decode(shortUrl);
}