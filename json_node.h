#pragma once
#include<string>
#include<unordered_map>
#include<vector>

namespace json{

    class json_node;
    typedef std::unordered_map<std::string, json_node*> node_map;
    typedef std::vector<json_node*> node_vec;
    typedef enum {
            NUMBER,
            STRING,
            ARRAY,
            OBJECT,
            TRUE,
            FALSE,
            NUL,
            UNKNOWN
        } node_type;

    class json_node
    {
    public:
        json_node(node_type type);
        ~json_node();

        static json_node* create_num_node(int num);
        static json_node* create_str_node(std::string str);
        static json_node* create_bool_node(bool b);
        static json_node* create_null_node();
        static json_node* create_array_node();
        static json_node* create_object_node();

        node_map get_node_map();
        std::string get_string();
        node_type get_node_type();
        void add_to_vec(json_node* node);
        void add_to_map(std::string key, json_node* node);
    private:
        node_type type;
        std::string name;
        union {
            double num;
            std::string str;
            node_map map;
            node_vec vec;
        };
    };

};