//
//  KiteJSONValidator.h
//  MCode
//
//  Created by Sam Duke on 15/12/2013.
//  Copyright (c) 2013 Airsource Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KiteJSONSchemaRefDelegate;

@interface KiteJSONValidator : NSObject

@property (nonatomic, weak) id<KiteJSONSchemaRefDelegate> delegate;

/**
 Validates json against a draft4 schema.
 @see http://tools.ietf.org/html/draft-zyp-json-schema-04
 
 @param jsonData The JSON to be validated
 @param schemaData The draft4 JSON schema to validate against
 @return Error if json is invalid. Nil if validated
 */

-(NSError*)validateJSONData:(NSData*)jsonData withSchemaData:(NSData*)schemaData;
-(NSError*)validateJSONInstance:(id)json withSchema:(NSDictionary*)schema;
-(NSError*)validateJSONInstance:(id)json withSchemaData:(NSData*)schemaData;
//TODO:add an interface to add a schema with a key, allowing a schema to only be validated once and then reused

/**
 Used for adding an ENTIRE document to the list of reference schemas - the URL should therefore be fragmentless.
 
 @param schemaData The data for the document to be converted to JSON
 @param url        The fragmentless URL for this document
 
 @return Error if the reference schema is invalid. Nil if was successfully added.
 */
-(NSError*)addRefSchemaData:(NSData*)schemaData atURL:(NSURL*)url;

/**
 Used for adding an ENTIRE document to the list of reference schemas - the URL should therefore be fragmentless.
 
 @param schemaData           The data for the document to be converted to JSON
 @param url                  The fragmentless URL for this document
 @param shouldValidateSchema Whether the new reference schema should be validated against the "root" schema.
 
 
 @return Error if the reference schema is invalid. Nil if was successfully added.
 */
-(NSError*)addRefSchemaData:(NSData*)schemaData atURL:(NSURL*)url validateSchema:(BOOL)shouldValidateSchema;

/**
 Used for adding an ENTIRE document to the list of reference schemas - the URL should therefore be fragmentless.
 
 @param schema The dictionary representation of the JSON schema (the JSON was therefore valid).
 @param url    The fragmentless URL for this document
 
 @return Error if the reference schema is invalid. Nil if was successfully added.
 */
-(NSError*)addRefSchema:(NSDictionary*)schema atURL:(NSURL*)url;

/**
 Used for adding an ENTIRE document to the list of reference schemas - the URL should therefore be fragmentless.
 
 @param schema               The dictionary representation of the JSON schema (the JSON was therefore valid).
 @param url                  The fragmentless URL for this document
 @param shouldValidateSchema Whether the new reference schema should be validated against the "root" schema.
 
 @return Error if the reference schema is invalid. Nil if was successfully added.
 */
-(NSError*)addRefSchema:(NSDictionary *)schema atURL:(NSURL *)url validateSchema:(BOOL)shouldValidateSchema;

@end

@protocol KiteJSONSchemaRefDelegate <NSObject>

-(NSData*)schemaValidator:(KiteJSONValidator*)validator requiresSchemaDataForRefURL:(NSURL*)refURL;
-(NSDictionary*)schemaValidator:(KiteJSONValidator*)validator requiresSchemaForRefURL:(NSURL*)refURL;

@end
