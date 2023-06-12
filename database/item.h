#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <vector>
#include "Poco/JSON/Object.h"
#include <optional>

namespace database
{
    class Item{
        private:
            long _id;
            std::string _name;
            std::string _category;
            std::string _description;
            float _price;
            bool _availability;

        public:
            static Item fromJSON(const std::string & str);

            long             get_id() const;
            const std::string &get_name() const;
            const std::string &get_category() const;
            const std::string &get_description() const;
            const float &get_price() const;
            const bool &get_availability() const;

            long&        id();
            std::string &name();
            std::string &category();
            std::string &description();
            float &price();
            bool &availability();

            static void init();
            static std::optional<Item> read_by_id(long id);
            static std::vector<Item> read_all();
            void save_to_mysql();
            static std::vector<Item> search_cart(std::string login);

            Poco::JSON::Object::Ptr toJSON() const;
    };
}

#endif