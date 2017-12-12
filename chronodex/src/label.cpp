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
      if (pointsLeft())
        return m_connector->basePoint() + S_LABEL_PADDING;

      float width = 100.0f;
      return m_connector->basePoint() - width - S_LABEL_PADDING;
    }

    inline bool pointsLeft() {
      float angle = m_connector->basePoint().angle(m_connector->endPoint());
      return angle - 90.0f < 0;
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