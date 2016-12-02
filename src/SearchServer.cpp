//
//  SearchServer.cpp
//
//  by jiahuan.liu
//  11/26/2016
//
#include "SearchServer.h"

std::string search::toJson(const vres_t& vres)
{
    std::string ret;
    
    std::vector<std::map<std::string, std::string>> list;
    std::map<std::string, std::string> tuple, object;
    
    for (const result_t& res : vres)
    {
        tuple.clear();
        tuple["title"] = res.title;
        tuple["url"] = res.url;
        list.push_back(tuple);
    }
    
    object["n"] = Common::tostr(vres.size());
    object["list"] = JsonUtil::buildJsonList(list);
    
    return JsonUtil::buildJsonObject(object);
}

SearchServer::SearchServer(int svrThNum, int schThNum, int schQSize)
:_searcher(schThNum, schQSize), _lsearcher(schThNum, schQSize){}

void SearchServer::init(std::string indexPath, std::string docFilesPath, std::string lindexPath)
{
    _searcher.load(indexPath, docFilesPath);
    _lsearcher.load(lindexPath, docFilesPath);
}