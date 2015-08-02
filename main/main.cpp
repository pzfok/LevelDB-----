#include <assert.h>
#include <string.h>
#include "leveldb/db.h"
#include <iostream>
  
int main()
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options,"./testdb", &db);
    assert(status.ok());
  
    //write key1,value1
    std::string key="key1";
    std::string putvalue = "value000000000000000";
    std::string getvalue;
  
    status = db->Put(leveldb::WriteOptions(), key,putvalue);
    assert(status.ok());
  
    status = db->Get(leveldb::ReadOptions(), key, &getvalue);
    assert(status.ok());
    std::cout<<"key1:"<<getvalue<<std::endl;
     
      
    delete db;
    return 0;
}