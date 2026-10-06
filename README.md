# `cardinal_direction` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)

A package két node-ból áll. A `/gen_point` koordinátákat generál, amit egy `geometry_msgs/Point` topic-ban hirdet. A `/calc_direction` feliratkozik erre a topicra, és egy `std_msgs/String` topicban kihirdeti, hogy melyik égtájba történt változás. 

Megvalósítás `ROS 2 Humble` alatt.
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/pretsbarnabas/pre_hc2_ajr
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select cardinal_direction --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch cardinal_direction cardinal_direction.launch.py
```

### Check
```r
ros2 topic echo /cardinal_direction
```


## Graph


```mermaid
graph LR
id1([/gen_point]):::red
id2(/point):::light
id3([/calc_direction]):::red
id4(/cardinal_direction):::light

id1 --> id2 --> id3 --> id4


classDef light fill:#34aec5,stroke:#152742,stroke-width:2px,color:#152742
classDef dark fill:#152742,stroke:#34aec5,stroke-width:2px,color:#34aec5
classDef white fill:#ffffff,stroke:#152742,stroke-width:2px,color:#152742
classDef red fill:#ef4638,stroke:#152742,stroke-width:2px,color:#fff
```