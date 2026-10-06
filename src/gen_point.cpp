#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"



int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("gen_point");
    auto point_pub = node->create_publisher<geometry_msgs::msg::Point>("point", 1);
    auto point = std::make_shared<geometry_msgs::msg::Point>();
    point->z = 10.0;
    std::vector<std::vector<float>> positions = {{10.0,10.0}, {11.0,10.0}, {12.0, 11.0}, {12.0, 12.0}, {11.0, 13.0}, {10.0, 13.0}, {9.0, 12.0}, {9.0, 11.0}};
    rclcpp::WallRate loop_rate(5);
    while (rclcpp::ok())
    {
        for(size_t i = 0; i<positions.size(); i++){
            point->x = positions[i][0];
            point->y = positions[i][1];
            point_pub->publish(*point);
            RCLCPP_INFO_STREAM(node->get_logger(), "Published point");
            rclcpp::spin_some(node);
            loop_rate.sleep();
        }
    }
    rclcpp::shutdown();
    return 0;
}