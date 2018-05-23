#include "metarfetcher.h"
#include <QDebug>
#include "curl/curl.h"
#include "curl/easy.h"
#include <curl/curlver.h>
#include <sstream>
#include <iostream>
using namespace std;
long response_code;
QString city;


struct MemoryStruct {
    char *memory;
    size_t size;
};



static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
    if(mem->memory == NULL) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

QString getReport(QString city) {


    qDebug() << city;
    CURL *curl_handle = nullptr;
    CURLcode res;

    struct MemoryStruct chunk;

    chunk.memory = (char*)malloc(1);  /* will be grown as needed by the realloc above */
    chunk.size = 0;    /* no data at this point */

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();
    ostringstream os;
    os << "http://tgftp.nws.noaa.gov/data/observations/metar/decoded/" << city.toStdString() << ".TXT";
    string s =os.str();
    cout << s;

    /* specify URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, s.c_str());

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

    /* we pass our 'chunk' struct to the callback function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    /* some servers don't like requests that are made without a user-agent
    field, so we provide one */
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    /* get it! */
    res = curl_easy_perform(curl_handle);

    /* check for errors */
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        //QCoreApplication::exit(1);
    }



    else {
        /*
        * Now, our chunk.memory points to a memory block that is chunk.size
        * bytes big and contains the remote file.
        *
        * Do something nice with it!
        */
        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);
        qDebug() << response_code;


        printf("%lu bytes retrieved\n", (long)chunk.size);
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
    //  curl_handle.
    if(response_code == 200) {
        qDebug() << chunk.memory;
        QString weather(chunk.memory);
        return weather;

    }
    return "";
}
