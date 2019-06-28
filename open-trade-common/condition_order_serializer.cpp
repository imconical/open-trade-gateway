#include "condition_order_serializer.h"

SerializerConditionOrderData::SerializerConditionOrderData()
	:dump_all(false)
{
}

bool SerializerConditionOrderData::FilterMapItem(const std::string& key
	, ConditionOrder& value)
{
	if (dump_all)
		return true;
	bool b = value.changed;
	value.changed = false;
	return b;
}

void SerializerConditionOrderData::DefineStruct(ContingentCondition& d)
{
	AddItemEnum(d.contingent_type
		, ("contingent_type")
		, { { EContingentType::market_open, ("market_open") },
		{ EContingentType::time, ("time") },
		{ EContingentType::price, ("price") },
		{ EContingentType::price_range, ("price_range") },
		{ EContingentType::break_even, ("break_even") },
		});

	AddItem(d.exchange_id, ("exchange_id"));

	AddItem(d.instrument_id, ("instrument_id"));

	AddItem(d.is_touched, ("is_touched"));

	AddItemEnum(d.market_status
		, ("market_status")
		, { { EMarketStatus::before_trading , ("before_trading") },
		{ EMarketStatus::no_trading, ("no_trading") },
		{ EMarketStatus::continous, ("continous") },
		{ EMarketStatus::auction_ordering, ("auction_ordering") },
		{ EMarketStatus::auction_balance, ("auction_balance") },
		{ EMarketStatus::auction_match, ("auction_match") },
		{ EMarketStatus::is_closed, ("is_closed") },
		});

	AddItem(d.contingent_price, ("contingent_price"));

	AddItemEnum(d.price_relation_type
		, ("price_relation_type")
		, { { EPriceRelationType::G, ("G") },
		{ EPriceRelationType::GE, ("GE") },
		{ EPriceRelationType::L, ("L") },
		{ EPriceRelationType::LE, ("LE") },
		});

	AddItem(d.contingent_time, ("contingent_time"));

	AddItem(d.contingent_price_left, ("contingent_price_left"));

	AddItem(d.contingent_price_right, ("contingent_price_right"));

	AddItem(d.break_even_price, ("break_even_price"));
}

void SerializerConditionOrderData::DefineStruct(ContingentOrder& d)
{
	AddItem(d.exchange_id, ("exchange_id"));

	AddItem(d.instrument_id, ("instrument_id"));

	AddItemEnum(d.direction
		, ("direction")
		, { { EOrderDirection::buy, ("BUY") },
		{ EOrderDirection::sell, ("SELL") },
		});

	AddItemEnum(d.offset
		, ("offset")
		, { { EOrderOffset::open, ("OPEN") },
		{ EOrderOffset::close, ("CLOSE") },
		{ EOrderOffset::close_today, ("CLOSETODAY") },
		{ EOrderOffset::reverse, ("REVERSE") },
		});

	AddItemEnum(d.volume_type
		, ("volume_type")
		, { { EVolumeType::num, ("NUM") },
		{ EVolumeType::close_all, ("CLOSE_ALL") },
		});

	AddItem(d.volume, ("volume"));

	AddItemEnum(d.price_type
		, ("price_type")
		, { { EPriceType::contingent, ("CONTINGENT") },
		{ EPriceType::consideration, ("CONSIDERATION") },
		{ EPriceType::market, ("MARKET") },
		{ EPriceType::over, ("OVER") },
		{ EPriceType::limit, ("LIMIT") },
		});

	AddItem(d.limit_price, ("limit_price"));
}


void SerializerConditionOrderData::DefineStruct(ConditionOrder& d)
{
	AddItem(d.order_id, ("order_id"));

	AddItem(d.trading_day, ("trading_day"));

	AddItem(d.insert_date_time, ("insert_date_time"));

	AddItem(d.condition_list, ("condition_list"));

	AddItemEnum(d.conditions_logic_oper
		, ("conditions_logic_oper")
		, { { ELogicOperator::logic_and, ("AND") },
		{ ELogicOperator::logic_or, ("OR") }, });

	AddItem(d.order_list, ("order_list"));

	AddItemEnum(d.time_condition_type
		, ("time_condition_type")
		, { { ETimeConditionType::GFD, ("GFD") },
		{ ETimeConditionType::GTC, ("GTC") },
		{ ETimeConditionType::GTD, ("GTD") },
		});

	AddItem(d.GTD_date, ("GTD_date"));

	AddItem(d.is_cancel_ori_close_order, ("is_cancel_ori_close_order"));

	AddItemEnum(d.status
		, ("status")
		, { { EConditionOrderStatus::cancel, ("cancel") },
		{ EConditionOrderStatus::live, ("live") },
		{ EConditionOrderStatus::suspend, ("suspend") },
		{ EConditionOrderStatus::touched, ("touched") },
		});
}

void SerializerConditionOrderData::DefineStruct(ConditionOrderData& d)
{
	AddItem(d.broker_id, ("broker_id"));
	AddItem(d.user_id, ("user_id"));
	AddItem(d.user_password, ("user_password"));
	AddItem(d.trading_day, ("trading_day"));
	AddItem(d.condition_orders, ("condition_orders"));
}

void SerializerConditionOrderData::DefineStruct(req_insert_condition_order& d)
{
	AddItem(d.aid, ("aid"));
	AddItem(d.user_id, ("user_id"));
	AddItem(d.order_id, ("order_id"));
	AddItem(d.condition_list, ("condition_list"));
	AddItemEnum(d.conditions_logic_oper
		, ("conditions_logic_oper")
		, { { ELogicOperator::logic_and, ("AND") },
		{ ELogicOperator::logic_or, ("OR") }, });
	AddItem(d.order_list, ("order_list"));
	AddItemEnum(d.time_condition_type
		, ("time_condition_type")
		, { { ETimeConditionType::GFD, ("GFD") },
		{ ETimeConditionType::GTC, ("GTC") },
		{ ETimeConditionType::GTD, ("GTD") },
		});
	AddItem(d.GTD_date, ("GTD_date"));
	AddItem(d.is_cancel_ori_close_order, ("is_cancel_ori_close_order"));	
}
