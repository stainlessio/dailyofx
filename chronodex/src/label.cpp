#include "ofMain.h"
#include "constructors.h"
#include "interfaces.h"

class LabelImpl : public ILabel {
  public:
    static float S_LABEL_PADDING;

    LabelImpl(std::string text)
      : LabelImpl(text, new_connector({0,0}, {0,1}))
    { }

    LabelImpl(std::string text, IConnector *connector)
      : m_value(text)
      , m_connector(connector)
    {

    }

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
        ofDrawBitmapString(m_value, m_labelPosition);
        ofPopStyle();
      }
    }

    void update() override {
      if (m_connector) {
        m_connector->update();
        m_labelPosition = calculate_label_position();
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
    ofPoint m_labelPosition;

    inline ofPoint calculate_label_position() {
      ofPoint retval = m_connector->basePoint();
      retval.y += 5; // Center vertically
      switch (m_connector->direction()) {
        case ConnectorDirection::NE:
        case ConnectorDirection::SE:
          retval.x += 5;
          break;
        case ConnectorDirection::NW:
        case ConnectorDirection::SW:
          retval.x -= (float)m_value.length() * 10.0f;
          break;
      }
      return retval;
    }
};

float LabelImpl::S_LABEL_PADDING = 10.0f;

ILabel *new_label(std::string text, ofPoint basePosition, ofPoint labelPosition) {
  IConnector* connector = new_connector(basePosition, labelPosition);
  return new LabelImpl(text, connector);
}

ILabel *new_label(std::string text, IConnector *connector) {
  return new LabelImpl(text, connector);
}