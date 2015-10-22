# Introduction #

Traitor is an algorithmic trading platform and web frontend that allows users to create and test trading strategies in a community setting.


# Details #

# Front End Design Thoughts #

Once the user logs in she will land on the dashboard page. The dashboard consists of two areas; a workspace area(a context sensitive area where the user can manipulate any of the framework objects) and a toolbox(in its simplest form the tool box holds items that can be dropped on to the workspace area and reconfigured).

In its first version the workspace area will support three different contexts. These contexts are unique items in the framework but all can interact together.

The first context is simply a stock quote context where the user will see most recent stock information for a given stock.

The second context is an algorithm context where the user can build and test algorithms on specific stocks.

The third context is an indicator context, here the user will be able to build and test  specific indicators.

# Autumn #
Autumn is the name of the overall backend daemon

Montior is the deamon that handles monitoring algorithms and responding to buy/sell indicator signals.

Interpreter is the daemon that handles interpreting user generated LUA scripts.

These may be all under one pid or seperated.