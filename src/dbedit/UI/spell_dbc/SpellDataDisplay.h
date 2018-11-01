#ifndef TRINITY_DBEDIT_SPELLDATADISPLAY_H
#define TRINITY_DBEDIT_SPELLDATADISPLAY_H

#include <QGroupBox>
#include <vector>

struct SpellEntry;

class SpellDataElement : public QGroupBox
{
    Q_OBJECT

    protected:
        SpellDataElement(QWidget* parent) : QGroupBox(parent) {}

    Q_SIGNALS:
        void ValueChanged();

    public:
        virtual void Setup() = 0;
        virtual void BuildEntry(SpellEntry&) const = 0;
        virtual void SetEntry(SpellEntry const*) = 0;
        //virtual void UpdateLayoutAndValidate(SpellEntry const*, std::vector<std::string>& errors, std::vector<std::string>& warnings) = 0;
};

class SpellAttributes;
class SpellAuraProperties;
class SpellBaseProperties;
class SpellCasterProperties;
class SpellEffectProperties;
class SpellProperties;
class SpellSourceSelector;
class SpellTargetProperties;

class SpellDataDisplay : public QWidget
{
    Q_OBJECT

    public:
        SpellDataDisplay(QWidget* parent = nullptr) : QWidget(parent) {}
        void Setup();
        void SetSpell(unsigned int);

    Q_SIGNALS:
        void HavePendingChanges(bool);

    public Q_SLOTS:
        void ChildValueChanged() { Q_EMIT HavePendingChanges(true); }
        void SaveToDB();
        void Redraw();

    private:
        SpellSourceSelector*    _sourceSelector     = nullptr;
        SpellBaseProperties*    _baseProperties     = nullptr;
        SpellProperties*        _spellProperties    = nullptr;
        SpellAuraProperties*    _auraProperties     = nullptr;
        SpellCasterProperties*  _casterProperties   = nullptr;
        SpellTargetProperties*  _targetProperties   = nullptr;
        SpellAttributes*        _attributes         = nullptr;
        SpellEffectProperties*  _effect0            = nullptr;
        SpellEffectProperties*  _effect1            = nullptr;
        SpellEffectProperties*  _effect2            = nullptr;
};

#endif
