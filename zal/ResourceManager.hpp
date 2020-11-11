#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager()
    {
        resource = new Resource;
    }
    ResourceManager(const ResourceManager& rm)                  
    {
        resource = new Resource;
        *resource = *rm.resource;
    }
    ResourceManager& operator=(const ResourceManager& rm)       
    {
        if (&rm == this) return *this;
        delete resource;
        resource = new Resource();
        *resource = *rm.resource;
        return *this;
    }
    ResourceManager(ResourceManager&& rm) noexcept : resource(rm.resource) 
    {
        rm.resource = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& rm) noexcept   
    {
        if (&rm == this) return *this;
        delete resource;
        resource = rm.resource;
        rm.resource = nullptr;
        return *this;
    }
    Resource& operator*() const { return *resource; }           
    Resource* operator->() const { return resource; }          
    bool isNull() const { return resource == nullptr; }        
    double get() { return resource->get(); }                    

    ~ResourceManager() { delete resource;}                      

private:
    Resource* resource;
};
