#pragma once

#include <bdn/Notifier.h>
#include <bdn/Text.h>
#include <bdn/ui/View.h>
#include <bdn/ui/ViewUtilities.h>

namespace bdn::ui
{

    namespace detail
    {
        VIEW_CORE_REGISTRY_DECLARATION(Label)
    }

    class Label : public View
    {
      public:
        Property<Text> text;
        Property<bool> wrap = false;
        Property<Text::TruncateMode> truncateMode = Text::TruncateMode::Tail;

      public:
        Label(std::shared_ptr<ViewCoreFactory> viewCoreFactory = nullptr);

      public:
        Notifier<const std::string &> &onLinkClick();

      protected:
        void bindViewCore() override;
        void updateFromStylesheet() override;

      private:
        Notifier<const std::string &> _onLinkClick;
        WeakCallback<void(std::string)>::Receiver _linkClickCallbackReceiver;

      public:
        class Core
        {
          public:
            Property<Text> text;
            Property<bool> wrap = false;
            Property<Text::TruncateMode> truncateMode;

          public:
            virtual ~Core() = default;

          public:
            WeakCallback<void(std::string)> _linkClickCallback;
        };
    };
}
