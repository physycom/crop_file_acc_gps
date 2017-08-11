---
documentclass: physycomen
title:  "crop_file_acc_gps"
author: "Guidetti, Di Cristina, Sinigardi"
---

<a href="http://www.physycom.unibo.it"> 
<div class="image">
<img src="https://cdn.rawgit.com/physycom/templates/697b327d/logo_unibo.png" width="90" height="90" alt="© Physics of Complex Systems Laboratory - Physics and Astronomy Department - University of Bologna"> 
</div>
</a>
<a href="https://travis-ci.org/physycom/crop_file_acc_gps"> 
<div class="image">
<img src="https://travis-ci.org/physycom/crop_file_acc_gps.svg?branch=master" width="90" height="20" alt="Build Status"> 
</div>
</a>
<a href="https://ci.appveyor.com/project/cenit/crop-file-acc-gps"> 
<div class="image">
<img src="https://ci.appveyor.com/api/projects/status/3fc4fxuf2jitbovr?svg=true" width="90" height="20" alt="Build Status"> 
</div>
</a>


### Installation
**CMake**, a **C++11** compatible compiler and **boost** libraries are required. To build the executable, clone the repo and then type  
```
mkdir build ; cd build ; cmake .. ; cmake --build . --target install
```
With CMake you can also deploy projects for the most common IDEs.  


### Description
Simply parses all files in a folder, making a copy containing a selected time window.
Files should follow the structure:

`time value1 value2 value3`

A subfolder "crop" will be created, and files with only the selected time window will be created inside it.

Only works via command line arguments.

`./crop_file_acc_gps folder_name`

Example file:
```
4968443.308	44.499387	11.354015	0.208800
4968443.462	44.499387	11.354015	0.489600
4968443.615	44.499387	11.354015	0.381600
4968443.769	44.499387	11.354015	0.518400
4968443.923	44.499387	11.354015	0.486000
4968444.077	44.499387	11.354015	0.097200
4968444.231	44.499387	11.354015	0.453600
4968444.385	44.499387	11.354015	0.169200
4968444.538	44.499387	11.354015	0.054000
4968444.692	44.499388	11.354015	0.435600
4968444.846	44.499388	11.354015	0.536400
4968445.000	44.499388	11.354015	0.468000
4968445.100	44.499388	11.354015	0.406800
4968445.200	44.499388	11.354015	0.270000
4968445.300	44.499388	11.354014	0.244800
4968445.400	44.499388	11.354014	0.039600
4968445.500	44.499389	11.354014	0.511200
4968445.600	44.499389	11.354014	0.759600
```
