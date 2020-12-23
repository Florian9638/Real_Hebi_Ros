# Real_Hebi_Ros

Documentation

Download the following Hebi ROS packages (git clone):

hebi_cpp_api_ros_examples = contains useful fies to move the real robot (cpp files, robot_hardware_interface) as well as the gains (<robot_name>_params.yaml)
hebi_description = contains xacro components to build a custom robot
hebi_gazebo = not useful if you want to move the real robot with moveit and visualize it in Rviz. (Maybe useful if you want to simulate the custom robot in Gazebo, maybe not)
hebi_moveit_configs = contains the folders (/config /launch) created by the moveit setup assistant

First step
Start with the hebi_description package. Inside the /urdf folder you find all the robot components to create your custom robot. Inside /kits folder you are going to creat your xacro. I suggest to copy an already existing file (e.g A-2084-01.xacro) and modify just the name (choose a desired name that you are going to use also for the next steps) and the buttom part of the script adding or removing components (actuators, brackets, link, gripper). This xacro file is a “compressed” file, you have to “decompress” it. In the terminal reach the folder where you compressed xacro file is and run:
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

# Note: the "moveit_joints" must matches the configuration from the MoveIt config; only
# required when running MoveIt examples
moveit_joints: ["Arm/J1_shoulder"] # name of the joint specified in the xacro

Go in /config /gains and create <robot_name>_gains.xml. I suggest to copy an already existing file and modify it (e.g. A-2084-01_gains.xml). The amount of gain values must match with the amount of your robot joints. (e.g. if you have 2 joints, specify 2 kp values).
Go in /config /hrdf and create <robot_name>.hrdf, again I suggest to copy an already existing file and modify it.

Fourth step
Open the terminal, go to catkin_ws and run:
$ catkin build
$ source devel/setup.bash
$ roslaunch hebi_cpp_api_examples arm_moveit_node_<robot_name>.launch



To do & questions
    • move both the real robot and the simulated one in gazebo via moveit (mayby “transmission” must be added in the xacro file. Do we need a separate controller or is one enough?)
