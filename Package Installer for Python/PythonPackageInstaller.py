"""
This is a python script to install/update desired packages.
The input for the script is a JSON file with all the dependencies.
If any package fails to install/update, it is printed on a new line.
If all the packages are installed/updated, it gives a success message.
The script also handles cases like if a package fails to install/update, it won't affect the execution of the script.
"""

import json
import subprocess

def install(package, version):
    
    try:
        subprocess.check_call(["python", '-m', 'pip', 'install',"--upgrade", package + "==" + version])     #install/update the desired version of the package
        return 1
    except Exception:
        print("Failed to install/update: "+ package +" "+ version)          #package failed to install/update
        return 0

if __name__ == '__main__':
    
    f = open('dependencies.json', 'r')
    string = json.load(f)                                                   #convert the JSON input to a dictionary
    
    flag = 0
    count = 0

    for p in string['dependencies']:
        flag += install(p, string['dependencies'][p])                       #install/update each package one by one
        count += 1

    if flag == count:                                                       #prints success message if all the packages are installed/updated
        print("Successfully installed/updated all the packages!")
