    #include <libudev.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <vector>
    #include <iostream>
    #include <unordered_map>

    #define SUBSYSTEM "video4linux"

    using vec  = std::vector<std::string>;
    using umap = std::unordered_map<std::string,std::string>;


    vec idVector;
    vec ports;

    umap enumerate_devices(struct udev* udev)
    {
        umap cameraInfo;
        const char* idNum = NULL;
        struct udev_enumerate* enumerate = udev_enumerate_new(udev);

        udev_enumerate_add_match_subsystem(enumerate, SUBSYSTEM);
        
        udev_enumerate_scan_devices(enumerate);

        struct udev_list_entry* devices = udev_enumerate_get_list_entry(enumerate);
        struct udev_list_entry* entry;

        udev_list_entry_foreach(entry, devices) {
            const char* path = udev_list_entry_get_name(entry);
            struct udev_device* dev = udev_device_new_from_syspath(udev, path);

            auto x = udev_device_get_devnode(dev);

            idNum = udev_device_get_sysattr_value(dev, "serial");

            while (idNum == NULL) {
                auto v = udev_device_get_parent(dev);
                idNum = udev_device_get_sysattr_value(v, "serial");
                dev = v;
            }
            if(idNum != NULL){
                //printf("Serial is: %s\n",idNum);
                // idVector.push_back(idNum);
                // ports.push_back(udev_device_get_devnode(dev));
                // cameraInfo[idNum] = udev_device_get_devnode(dev);
                cameraInfo[idNum] = x;
                //std::cout << path <<"\n";
            }
        }
        
        udev_enumerate_unref(enumerate);
        return cameraInfo;
    }

    int main(void)
    {
        struct udev* udev = udev_new();
        if (!udev) {
            // fprintf(stderr, "udev_new() failed\n");
            std::cout << "udev_new() failed\n";
            return 1;
        }
        
        enumerate_devices(udev);
        for(auto item : enumerate_devices(udev)){
            std::cout << "Serial is: "<< item.first <<" " <<"port is: " <<item.second <<"\n";
        }
        
        udev_unref(udev);
        return 0;
    }
