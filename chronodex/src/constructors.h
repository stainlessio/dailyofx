#pragma once

#include "ofTypes.h"

class ILabel;
class IConnector;
class ISection;
struct SectionSpecification;

ILabel *new_label(std::string value, ofPoint baseConnectionPoint, ofPoint labelLocation);
ILabel *new_label(std::string value, IConnector *connector);
IConnector *new_connector(ofPoint basePoint, ofPoint endPoint);
ISection *new_section(SectionSpecification spec, ofColor color, std::string value);