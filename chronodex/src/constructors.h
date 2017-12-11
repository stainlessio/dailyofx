#pragma once

#include "ofTypes.h"

class ILabel;
class IConnector;

ILabel *new_label(std::string value, ofPoint baseConnectionPoint, ofPoint labelLocation);
IConnector *new_connector();