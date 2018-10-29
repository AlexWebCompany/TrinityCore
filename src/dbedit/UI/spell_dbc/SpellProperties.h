#ifndef TRINITY_DBEDIT_SPELLPROPERTIES_H
#define TRINITY_DBEDIT_SPELLPROPERTIES_H

#include "SearchableDropdownDecl.h"
#include <QGroupBox>
#include <unordered_map>

class QCheckBox;
class QDoubleSpinBox;
class QLabel;
class QSpinBox;
class QStackedWidget;
struct SpellEntry;
enum SpellSchools;

class SelectorBase : public QGroupBox
{
    Q_OBJECT

    public:
        SelectorBase(QWidget* parent) : QGroupBox(parent) {}
        QCheckBox* MakeBox(uint32, char const*);
        void SetMask(uint32);
        uint32 GetMask() const;

    Q_SIGNALS:
        void ValueChanged();

    protected:
        std::unordered_map<QCheckBox*, uint32> _checkboxes;
};

class SpellSchoolSelector : public SelectorBase
{
    public:
        SpellSchoolSelector(QWidget* parent = nullptr);
};

class CastInterruptSelector : public SelectorBase
{
    public:
        CastInterruptSelector(QWidget* parent = nullptr);
};

class ChannelInterruptSelector : public SelectorBase
{
    public:
        ChannelInterruptSelector(QWidget* parent = nullptr);
};

class SpellProperties : public QGroupBox
{
    Q_OBJECT

    public:
        SpellProperties(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void SetEntry(SpellEntry const*);
        void BuildEntry(SpellEntry&) const;

    Q_SIGNALS:
        void ValueChanged();

    private Q_SLOTS:
        void PowerTypeChanged();

    private:
        SpellDamageClassDropdown*       _damageClass;
        SpellPreventionTypeDropdown*    _preventionType;

        PowerTypeDropdown*              _powerType;
        QStackedWidget*                 _powerTypeSub;
        enum PowerTypePages             { PAGE_REGULAR = 0, PAGE_RUNE = 1 };
        QSpinBox*                       _manaCost;
        QLabel*                         _manaCostPctPrefix;
        QSpinBox*                       _manaCostPercentage;
        QLabel*                         _manaCostPctSuffix;
        RuneCostDropdown*               _runeCost;
        QLabel*                         _upkeepLabel;
        QWidget*                        _upkeepWidget;
        QSpinBox*                       _channelCost;
        QSpinBox*                       _channelCostPerLevel;

        SpellCastTimeDropdown*          _castTime;
        QDoubleSpinBox*                 _recoveryTime;
        QSpinBox*                       _spellCategory;
        QDoubleSpinBox*                 _categoryCooldown;
        QSpinBox*                       _gcdCategory;
        QDoubleSpinBox*                 _gcdDuration;

        SpellSchoolSelector*            _spellSchools;
        CastInterruptSelector*          _interruptFlags;
        ChannelInterruptSelector*       _channelInterruptFlags;

        uint32 _manaCostPerLevel;
};

#endif
