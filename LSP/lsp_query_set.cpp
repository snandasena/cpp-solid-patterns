//
// Created by sajith on 4/17/21.
//

#include <iostream>
#include <vector>


template<typename Model>
class ORMQueryset
{
public:
    virtual ~ORMQueryset() = default;
    virtual ORMQueryset &filterObjects(std::string, std::string) const = 0;
    virtual ORMQueryset &orderObjects(std::string, std::string) const = 0;
    virtual std::vector<Model> getObjects() const = 0;
    virtual unsigned updateObjects() = 0;
    virtual unsigned deleteObjects() = 0;
};


template<typename Model>
class Database1ORMQueryset : public ORMQueryset<Model>
{
public:
    ORMQueryset<Model> &filterObjects(std::string, std::string) const override;

    ORMQueryset<Model> &orderObjects(std::string, std::string) const override;

    std::vector<Model> getObjects() const override;

    unsigned updateObjects() override;

    unsigned deleteObjects() override;
};



