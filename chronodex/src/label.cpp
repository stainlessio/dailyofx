#include "ofMain.h"
#include "constructors.h"
#include "interfaces.h"

class LabelImpl : public ILabel {
  public:
    LabelImpl(std::string text)
      : m_value(text)
      , m_connector(new_connector())
    { }

    ~LabelImpl() override {
      if (m_connector != nullptr) {
        delete m_connector;
      }
    }

    void draw() override {
      if (m_connector) {
        ofPushStyle();
        ofSetColor(0,0,0);
        m_connector->draw();
        ofPoint labelPosition = calculate_label_position();
        ofDrawBitmapString(m_value, labelPosition);
        ofPopStyle();
      }
    }

    void update() override {
      if (m_connector) {
        m_connector->update();
      }
    }

    ILabel* text(std::string value) override {
      m_value = value;
      return this;
    }

    const std::string text() const override {
      return m_value;
    }

    ILabel* connector(IConnector &connector) override {
      m_connector = &connector;
      return this;
    }

    const IConnector& connector() const override {
      return *m_connector;
    }

    IConnector& connectorMut() const override {
      return *m_connector;
    }

  private:
    std::string m_value;
    IConnector *m_connector;

    ofPoint calculate_label_position() {
      return m_connector->basePoint();
    }
};

ILabel *new_label(std::string text, ofPoint basePosition, ofPoint labelPosition) {
  // Make connector
  // Make label

  LabelImpl* label = new LabelImpl(text);
  label->connectorMut().basePoint(basePosition);
  label->connectorMut().endPoint(labelPosition);

  return label;
}