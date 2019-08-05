#pragma once

#include <bdn/ui/View.h>
#include <bdn/ui/ViewUtilities.h>

#include <deque>

namespace bdn::ui
{
    namespace detail
    {
        VIEW_CORE_REGISTRY_DECLARATION(NavigationView)
    }

    class NavigationView : public View
    {
      public:
        NavigationView(std::shared_ptr<ViewCoreFactory> viewCoreFactory = nullptr);
        ~NavigationView() override = default;

        void pushView(std::shared_ptr<View> view, std::string title);
        void popView();

      public:
        std::list<std::shared_ptr<View>> childViews() override;

      protected:
        void bindViewCore() override;

      public:
        class Core
        {
          public:
            virtual void pushView(std::shared_ptr<View> view, std::string title) = 0;
            virtual void popView() = 0;

            virtual std::list<std::shared_ptr<View>> childViews() = 0;
        };
    };
}
