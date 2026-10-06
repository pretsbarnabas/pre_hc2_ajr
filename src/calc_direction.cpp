#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "std_msgs/msg/string.hpp"

class CardinalDirection : public rclcpp::Node
{
    private:
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
        rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr subscription;
        std::unique_ptr<geometry_msgs::msg::Point> prev_point;
    public:
        CardinalDirection() : Node("calc_direction")
        {
            publisher = this->create_publisher<std_msgs::msg::String>("cardinal_direction", 1);
            subscription = this->create_subscription<geometry_msgs::msg::Point>("point", 1, std::bind(&CardinalDirection::topic_callback, this, std::placeholders::_1));
        }

    private:
        void topic_callback(const geometry_msgs::msg::Point::SharedPtr msg)
        {
            if(prev_point == nullptr){
                prev_point = std::make_unique<geometry_msgs::msg::Point>();
                prev_point->x = msg->x;
                prev_point->y = msg->y;
                prev_point->z = msg->z;
                return;
            }
            auto message = std_msgs::msg::String();
            message.data = "Object moved ";
            
            if(prev_point->x == msg->x && prev_point->y == msg->y){
                message.data = "Object did not move";
            }
            
            if(prev_point->y < msg->y){
                message.data += "North";
            }
            else if(prev_point->y > msg->y){
                message.data += "South";
            }
            if(prev_point->x < msg->x){
                message.data += "East";
            }
            else if(prev_point->x > msg->x){
                message.data += "West";
            }


            RCLCPP_INFO(this->get_logger(), "Publishing direction change");
            publisher->publish(message);

            prev_point->x = msg->x;
            prev_point->y = msg->y;
        }

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CardinalDirection>());
  rclcpp::shutdown();
  return 0;
}