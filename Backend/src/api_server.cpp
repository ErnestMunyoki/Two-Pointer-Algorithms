#include <httplib.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "ReversingString.hpp"
#include "PalindromeChecker.hpp"
#include "RemoveDuplicate.hpp"
#include "MergeSortedArrays.hpp"

using json = nlohmann::json;

// Helper function to set CORS headers
void setCORSHeaders(httplib::Response& res) {
    res.set_header("Access-Control-Allow-Origin", "*");
    res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "Content-Type");
}

int main() {
    httplib::Server svr;
    
    // Handle OPTIONS requests for CORS
    svr.Options(".*", [](const httplib::Request&, httplib::Response& res) {
        setCORSHeaders(res);
        return;
    });
    
    // Reverse String endpoint
    svr.Post("/api/reverse", [](const httplib::Request& req, httplib::Response& res) {
        setCORSHeaders(res);
        try {
            auto body = json::parse(req.body);
            std::string str = body["str"];
            std::string original = str;
            TwoPointerAlgorithms::reverseString(str);
            
            json result;
            result["success"] = true;
            result["original"] = original;
            result["reversed"] = str;
            result["length"] = original.length();
            
            res.set_content(result.dump(), "application/json");
        } catch (const std::exception& e) {
            json error;
            error["success"] = false;
            error["error"] = e.what();
            res.status = 400;
            res.set_content(error.dump(), "application/json");
        }
    });
    
    // Palindrome Checker endpoint
    svr.Post("/api/palindrome", [](const httplib::Request& req, httplib::Response& res) {
        setCORSHeaders(res);
        try {
            auto body = json::parse(req.body);
            std::string str = body["str"];
            bool isPal = TwoPointerAlgorithms::isPalindrome(str);
            
            json result;
            result["success"] = true;
            result["string"] = str;
            result["isPalindrome"] = isPal;
            result["length"] = str.length();
            
            res.set_content(result.dump(), "application/json");
        } catch (const std::exception& e) {
            json error;
            error["success"] = false;
            error["error"] = e.what();
            res.status = 400;
            res.set_content(error.dump(), "application/json");
        }
    });
    
    // Remove Duplicates endpoint
    svr.Post("/api/remove-duplicates", [](const httplib::Request& req, httplib::Response& res) {
        setCORSHeaders(res);
        try {
            auto body = json::parse(req.body);
            std::vector<int> arr = body["array"];
            std::vector<int> original = arr;
            
            // Check if array is sorted
            for (size_t i = 1; i < arr.size(); i++) {
                if (arr[i] < arr[i-1]) {
                    json error;
                    error["success"] = false;
                    error["error"] = "Array must be sorted in ascending order";
                    res.status = 400;
                    res.set_content(error.dump(), "application/json");
                    return;
                }
            }
            
            int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
            std::vector<int> unique(arr.begin(), arr.begin() + newLength);
            
            json result;
            result["success"] = true;
            result["original"] = original;
            result["unique"] = unique;
            result["newLength"] = newLength;
            result["removed"] = original.size() - newLength;
            
            res.set_content(result.dump(), "application/json");
        } catch (const std::exception& e) {
            json error;
            error["success"] = false;
            error["error"] = e.what();
            res.status = 400;
            res.set_content(error.dump(), "application/json");
        }
    });
    
    // Merge Sorted Arrays endpoint
    svr.Post("/api/merge", [](const httplib::Request& req, httplib::Response& res) {
        setCORSHeaders(res);
        try {
            auto body = json::parse(req.body);
            std::vector<int> arr1 = body["array1"];
            std::vector<int> arr2 = body["array2"];
            
            // Check if arrays are sorted
            for (size_t i = 1; i < arr1.size(); i++) {
                if (arr1[i] < arr1[i-1]) {
                    json error;
                    error["success"] = false;
                    error["error"] = "First array must be sorted in ascending order";
                    res.status = 400;
                    res.set_content(error.dump(), "application/json");
                    return;
                }
            }
            for (size_t i = 1; i < arr2.size(); i++) {
                if (arr2[i] < arr2[i-1]) {
                    json error;
                    error["success"] = false;
                    error["error"] = "Second array must be sorted in ascending order";
                    res.status = 400;
                    res.set_content(error.dump(), "application/json");
                    return;
                }
            }
            
            std::vector<int> merged = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
            
            json result;
            result["success"] = true;
            result["array1"] = arr1;
            result["array2"] = arr2;
            result["merged"] = merged;
            
            res.set_content(result.dump(), "application/json");
        } catch (const std::exception& e) {
            json error;
            error["success"] = false;
            error["error"] = e.what();
            res.status = 400;
            res.set_content(error.dump(), "application/json");
        }
    });
    
    // Health check endpoint
    svr.Get("/api/health", [](const httplib::Request&, httplib::Response& res) {
        setCORSHeaders(res);
        json health;
        health["status"] = "ok";
        health["message"] = "Two-Pointer Algorithms API is running";
        res.set_content(health.dump(), "application/json");
    });
    
    std::cout << "API Server running on http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);
    
    return 0;
}
