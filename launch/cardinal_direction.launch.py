from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cardinal_direction',
            executable='gen_point'
        ),
        Node(
            package='cardinal_direction',
            executable='calc_direction'
        ),
    ])