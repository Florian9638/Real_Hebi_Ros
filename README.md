# Real_Hebi_Ros

Documentation

Download the following Hebi ROS packages (git clone):

hebi_cpp_api_ros_examples = contains useful fies to move the real robot (cpp files, robot_hardware_interface) as well as the gains (<robot_name>_params.yaml)
hebi_description = contains xacro components to build a custom robot
hebi_gazebo = useful if you want to simulate the custom robot in Gazebo
hebi_moveit_configs = contains the folders (/config /launch) created by the moveit setup assistant

First step
Start with the hebi_description package. Inside the /urdf folder you find all the robot components to create your custom robot. Inside /kits folder you are going to creat your xacro. I suggest to copy an already existing file (e.g A-2084-01.xacro) and modify just the name (choose a desired name that you are going to use also for the next steps) and the bottom part of the script adding or removing components (actuators, brackets, link, gripper). This xacro file is a “compressed” file, you have to “decompress” it. In the terminal reach the folder where you compressed xacro file is and run:
$ xacro --xacro-ns <filename>
Copy the output you get and and save it as xacro file, you will need it for the next step.

Second step
Open the moveit setup assistant:
$ roslaunch moveit_setup_assistant setup_assistant.launch
import your decompressed xacro file and go through all the steps. When creating a group, I do not used the HEBI_SIM_… joints.

Third step
Go in the hebi_cpp_api_examples package. In the /launch folder copy the arm_moveit_node.launch file and create the arm_moveit_node_<robot_name>.launch file.  In this file you have just to enter your robot name: (write the name used in the xacro file)
<arg name="arm_type" default="robot_name" />
Go  in /config folder and create your <robot_name>_params.yaml file (I suggest to copy and already existing file (e.g. A-2084-01_params.yaml) and modify it.

names: [ "J1_shoulder" ] # module name you find using Scope
families: [ "Arm" ] # family name you find using Scope
gains_package: "hebi_cpp_api_examples"
gains_file: "config/gains/<robot_name>_gains.xml"
hrdf_package: "hebi_cpp_api_examples"
hrdf_file: "config/hrdf/<robot_name>.hrdf"
home_position: [ -1.0 ]

moveit_joints: ["Arm/J1_shoulder"] # name of the joint specified in the xacro

Go in /config /gains and create <robot_name>_gains.xml. I suggest to copy an already existing file and modify it (e.g. A-2084-01_gains.xml). The amount of gain values must match with the amount of your robot joints. (e.g. if you have 2 joints, specify 2 kp values).
Go in /config /hrdf and create <robot_name>.hrdf, again I suggest to copy an already existing file and modify it.

Fourth step
Open the terminal, go to catkin_ws and run:
$ catkin build
$ source devel/setup.bash
$ roslaunch hebi_cpp_api_examples arm_moveit_node_<robot_name>.launch

This error may appear in the terminal:
Could not create arm! Check that family and names match actuators on the network.
[ WARN] [1609343322.041782993]: Could not initialize arm, trying again…
[ERROR] [1609343323.042008689]: Failed to find the following modules in family: Arm
[ERROR] [1609343323.042115305]: > J1_shoulder
[ERROR] [1609343323.042208391]: Could not initialize arm! Check for modules on the network, and ensure good connection (e.g., check packet loss plot in Scope). Shutting down…

To solve it, open first the Scope and move the robot using the application and then try to launch the ros command again.

How to move the arm
Option 1: use Moveit through Rviz
Option 2: use moveit through a ROS node. By opening the script, you can set a desired angle (1.57rad is set by default):

/Real_Hebi_Ros/catkin_ws/src/hebi_cpp_api_examples/scripts/single_joint_motion.py

If you want to run it, open a new terminal and use:
$ rosrun hebi_cpp_api_examples single_joint_motion.py


Gazebo

Remember to export first:
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/florian/Aigritec/Real_Hebi_Ros/catkin_ws/src/hebi_gazebo/plugin/gazebo9

export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:/home/florian/Aigritec/Real_Hebi_Ros/catkin_ws/src
Consider the hebi_gazebo package. Use the following command to check if everything works. Gazebo should open with the simulated robot you specify as arm_type in the command.
$ roslaunch hebi_gazebo arm_simulation.launch arm_type:=A-2085-06
To move both the simulated (Gazebo) robot and the real robot, copy the content of arm_simulation.launch (that you can find in the hebi_gazebo folder) and paste it inside arm_moveit_node_<robot_name>.launch (that you can find in the hebi_cpp_api_examples folder).
Comment or delete these parts otherwise you have them two times:
<arg name="arm_type" default="robot_name"/>
  <node name="robot_state_publisher" pkg="robot_state_publisher" type="robot_state_publisher" />
In the  hebi_cpp_api_examples folder create a copy of arm_node.launch and rename it arm_node_<robot_name>.launch. Open this file and add your robot name:
  <arg name="arm_type" default="robot_name" />
Finally, in  arm_moveit_node_<robot_name>.launch add your robot name in the following line, in order to match the launch file you created before:
  <include file="$(find hebi_cpp_api_examples)/launch/arm_node_<robot_name>.launch">
Use this command to be able to move both the simulated and the real robot:
$ roslaunch hebi_cpp_api_examples arm_moveit_node_<robot_name>.launch

(No transmittion was added in the xacro file and no additional controllers are needed to move the simulated robot in gazebo. Both the real and the simulated robot use the same controller.)

NOTE:
flomonk → used to move the real robot (just one actuator)
flobot → used to move both the simulated and the real robot (two actuators)
