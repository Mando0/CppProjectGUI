#ifndef __SHOP_H
#define __SHOP_H 2016
#include <iostream>
#include "Robot_Model.h"
#include <string>
#include <vector>
using namespace std;

class Shop {
  friend class View;
  friend class Controller;
  public:
    string name;
    string description;
    int part_number;
    int weight;
    int quantity;
    int cost;
    int power_consumed;
    int a_pick, b_pick, h_pick, l_pick, t_pick;
    int compartments;
    double max_speed;
    double energy;
    void set_quantity(int q) {
      quantity = q;
    }
    void create_model() {
      Robot_Model model;
      cout << "Which Head part do you want to choose: " << endl;
      for(int i = 0; i < head.size(); i++) {
        cout << i << ")  " <<  head[i].get_name() << endl;
      }
      cin >> h_pick;
      model.set_head(head[h_pick]);
      cout << "Which Arm part do you want to choose: " << endl;
      for(int i = 0; i < arm.size(); i++) {
        cout << i << ")  " << arm[i].get_name() << endl;
      }
      cin >> a_pick;
      model.set_arm(arm[a_pick]);
      cout << "Which Locomotor part do you want to choose: " << endl;
      for(int i = 0; i < locomotor.size(); i++) {
        cout << i << ") " << locomotor[i].get_name() << endl;
      }
      cin >> l_pick;
      model.set_locomotor(locomotor[l_pick]);
      cout << "Which Battery part do you want to choose: " << endl;
      for(int i = 0; i < battery.size(); i++) {
        cout << i << ") " << battery[i].get_name() << endl;
      }
      cin >> b_pick;
      model.set_battery(battery[b_pick]);
      cout << "Which Torso part do you want to choose: " << endl;
      for(int i = 0; i < torso.size(); i++) {
        cout << i << ") " << torso[i].get_name() << endl;
      }
      cin >> t_pick;
      model.set_torso(torso[t_pick]);
      cout << "What is name of model?: " << endl;
      cin >> name;
      model.set_name(name);
      cout << "What is model number?: " << endl;
      cin >> part_number;
      model.set_model_number(part_number);
      cout << "Total price of all parts is: ";
      cout << head[h_pick].get_cost() + arm[a_pick].get_cost() + torso[t_pick].get_cost() +
              battery[b_pick].get_cost() + locomotor[l_pick].get_cost() << endl;
      cout << "What shall model price be?: " << endl;
      cin >> cost;
      model.set_price(cost);
      robot_model.push_back(model);
    }
    void create_part();
    string get_robot_name() {
      return robot_model[0].get_name();
    }
    int get_robot_model_number() {
      return robot_model[0].get_model_number();
    }
    int get_robot_price() {
      return robot_model[0].get_price();
    }
    double get_robot_max_speed() {
      return robot_model[0].get_max_speed();
    }
    void create_head() {
      Head h;
      cout << "Name of head?: " << endl;
      cin >> name;
      h.set_name(name);
      cout << "Set description: " << endl;
      cin >> description;
      h.set_description(description);
      cout << "What is part number?: " << endl;
      cin >> part_number;
      h.set_part_number(part_number);
      cout << "What is the weight?: " << endl;
      cin >> weight;
      h.set_weight(weight);
      cout << "What is the cost?: " << endl;
      cin >> cost;
      h.set_cost(cost);
      head.push_back(h);
    }
    void get_head_vector() {
      cout << head[0].get_name() << endl;
    }
    void create_arm() {
      Arm a;
      cout << "Name of arm?: " << endl;
      cin >> name;
      a.set_name(name);
      cout << "Set description: " << endl;
      cin >> description;
      a.set_description(description);
      cout << "What is part number?: " << endl;
      cin >> part_number;
      a.set_part_number(part_number);
      cout << "What is the weight?: " << endl;
      cin >> weight;
      a.set_weight(weight);
      cout << "What is the cost?: " << endl;
      cin >> cost;
      a.set_cost(cost);
      arm.push_back(a);
    }
    void create_locomotor() {
      Locomotor l;
      cout << "Name of locomotor?: " << endl;
      cin >> name;
      l.set_name(name);
      cout << "Set description: :" << endl; 
      cin >> description;
      l.set_description(description);
      cout << "What is part number?: " << endl;
      cin >> part_number;
      l.set_part_number(part_number);
      cout << "What is the weight?: " << endl;
      cin >> weight;
      l.set_weight(weight);
      cout << "What is the cost?: " << endl;
      cin >> cost;
      l.set_cost(cost);
      cout << "What is the power consumed?: " << endl;
      cin >> power_consumed;
      l.set_power_consumed(power_consumed);
      cout << "What is max speed?: " << endl;
      cin >> max_speed;
      l.set_max_speed(max_speed);
      locomotor.push_back(l);
    }
    void create_battery() {
      Battery b;
      cout << "Name of battery?: " << endl;
      cin >> name;
      b.set_name(name);
      cout << "Set description: " << endl;
      cin >> description;
      b.set_description(description);
      cout << "What is part number?: " << endl;
      cin >> part_number;
      b.set_part_number(part_number);
      cout << "What is the weight?: " << endl;
      cin >> weight;
      b.set_weight(weight);
      cout << "What is the cost?: " << endl;
      cin >> cost;
      b.set_cost(cost);
      cout << "What is energy?: " << endl;
      b.set_energy(energy);
      battery.push_back(b);
    }
    void create_torso() {
      Torso t;
      cout << "Name of torso?: " << endl;
      cin >> name;
      t.set_name(name);
      cout << "Set description: " << endl;
      cin >> description;
      t.set_description(description);
      cout << "What is part number?: " << endl;
      cin >> part_number;
      t.set_part_number(part_number);
      cout << "What is the weight?: " << endl;
      cin >> weight;
      t.set_weight(weight);
      cout << "What is the cost?: " << endl;
      cin >> cost;
      t.set_cost(cost);
      cout << "How many compartments?(1-3): " << endl;
      cin >> compartments;
      t.set_compartments(compartments);
      torso.push_back(t);
    }
    void get_model_head_name() {
      robot_model[0].get_head();
    }
    void get_model_arm_name() {
      robot_model[0].get_arm();
    }
  private:
    vector<Robot_Model> robot_model;
    vector<Head> head;
    vector<Arm> arm;
    vector<Locomotor> locomotor;
    vector<Battery> battery;
    vector<Torso> torso;
};

#endif
